#include <iostream>
#include <fstream>

#include <filesystem>

#include <ParsePatch.hpp>

using namespace ParsePatch;

//#include "PatchParserCPP/patch_parser_cpp/patch_parser.hpp"

struct DiffImpl: public Diff {
	virtual void set_info(const std::string_view old_name, const std::string_view new_name, FileOp op, std::optional<std::vector<BinaryHunk>> binary_sizes, std::optional<FileMode> file_mode) {
		switch(op.code) {
			case FileOpCode::New:
			case FileOpCode::Renamed:
			case FileOpCode::None:
			{
				std::filesystem::path p = std::filesystem::relative(new_name, "b/");
				//std::cout << " " << (base / p).string();
				std::cout << " " << p.string();
			}
			break;
			default:
			break;
		}
	}

	virtual void add_line(uint32_t old_line, uint32_t new_line, std::string_view &&line) {}

	virtual void new_hunk() {}

	virtual void close() {}
};

struct PatchImpl: public Patch {
	DiffImpl diff{};
	virtual Diff *new_diff() {
		return &diff;
	}

	virtual void close() {
	}
};


int main(int argc, char* argv[]){
	if(argc != 4){
		std::cerr << "Usage: NinjaPatchScanner baseDir patchFile stampFile" << std::endl;
		return 1;
	}

	std::filesystem::path base{argv[1]};
	std::filesystem::path stampFile(argv[3]);

	std::ifstream patchFile(argv[2]);
	
	std::string rawPatch((std::istreambuf_iterator<char>(patchFile)), (std::istreambuf_iterator<char>()));

	std::cout << "ninja_dyndep_version = 1" << std::endl;

	std::string resultRuleName = stampFile.string();
	std::cout << "build " << resultRuleName << " | ";
	ParsePatch::PatchReader r;
	//r.tracing = &std::cerr;
	PatchImpl p;
	r.by_buf(rawPatch, p);
	std::cout << "  : dyndep" << std::endl;
	std::cout << "  restat = 1" << std::endl;
	std::cout << std::endl;

	return 0;
} 
