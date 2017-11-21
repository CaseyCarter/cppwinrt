#pragma once

#include "pch.h"

void add_winmd_spec(std::vector<std::wstring>& winmd_specs, std::wstring const& winmd_spec, bool is_ref);

void add_input_spec(std::wstring const& winmd_spec);

bool is_winmd(std::experimental::filesystem::path const& filename);

cppwinrt::generator<std::experimental::filesystem::path> enum_winmd_files(std::vector<std::wstring> const& winmd_specs);

std::vector<std::experimental::filesystem::path> get_winmd_files(std::vector<std::wstring> const& winmd_specs);

void prepare_metadata();