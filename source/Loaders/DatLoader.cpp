#include <Arcanum/Loaders/DatLoader.hpp>
#include <zlib.h>

using namespace Arcanum::Loaders;
using namespace Arcanum::Readers;

DatLoader::DatLoader(DatList* archiveList) :
	_ArchiveList(archiveList),
	_MemoryReader(&_ByteReader)
{
}

std::vector<uint8_t>& DatLoader::GetData(const std::string& path)
{
	_Result.clear();
	_Buffer.clear();

	DatItem* p = _ArchiveList->GetItem(path);

	int z_err = 0;

	if (p != nullptr)
	{
		_File.open(p->Archive, std::ios::binary);

		if (_File.is_open())
		{
			if (p->Type == DatItem::Uncompressed)
			{
				_File.seekg(p->Offset, std::ios::beg);

				_Result.resize(p->RealSize);

				_File.read((char*)_Result.data(), p->RealSize);
			}
			else if (p->Type == DatItem::Compressed)
			{
				_File.seekg(p->Offset, std::ios::beg);

				_Result.resize(p->RealSize);
				_Buffer.resize(p->PackedSize);

				_File.read((char*)&_Buffer[0], p->PackedSize);


				z_err = uncompress(_Result.data(), (uLongf*)&p->RealSize, _Buffer.data(), p->PackedSize);
			}

			_File.close();
		}
	}

	return _Result;
}

MemoryReader& DatLoader::GetFile(const std::string& path)
{
	_MemoryReader.Reset(GetData(path));

	return _MemoryReader;
}