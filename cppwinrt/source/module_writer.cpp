#include "pch.h"
#include "code_writer.h"
#include "settings.h"
#include "text_writer.h"
#include "strings.h"
#include "version.h"

using namespace std::experimental::filesystem;

namespace cppwinrt
{
    void write_header()
    {
        output out;
        write_projection(out);

        path filename = settings::output / settings::first_input.filename();
        filename.replace_extension(".h");
        out.save_as(filename.string());
    }

    void write_module()
    {
        write_header();

        meta::index_type const& index = meta::get_index();
        std::vector<meta::type const*> types;

        for (meta::index_pair const& ns : index)
        {
            for (meta::type const& type : ns.second)
            {
                if (!type.is_foundational())
                {
                    types.push_back(&type);
                }
            }
        }

        write_module_header(types);
        write_module_source(types);

        for (meta::type const* type : types)
        {
            if (type->is_class())
            {
                // TODO: use name relative to winmd name
                write_module_class_header(*type);
                write_module_class_source(*type);
            }
        }
    }
}
