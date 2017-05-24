#include "pch.h"
#include "code_writer.h"
#include "settings.h"
#include "text_writer.h"
#include "strings.h"
#include "version.h"

using namespace std::experimental::filesystem;

namespace cppwinrt
{
    namespace
    {
        void write_header()
        {
            output out;
            write_projection(out);
            path filename = settings::output / settings::first_input.filename();
            filename.replace_extension(".h");
            out.save_as(filename.string());
        }

        void create_natvis()
        {
            if (!settings::create_natvis)
            {
                return;
            }

            output out;
            write_natvis(out);
            path filename = settings::output / settings::first_input.filename();
            filename.replace_extension(".natvis");
            out.save_as(filename.string());
        }
    }

    void write_component()
    {
        write_header();
        create_natvis();
        meta::index_type const& index = meta::get_index();
        std::vector<meta::type const*> types;

        for (meta::index_pair const& pair : index)
        {
            for (meta::type const& type : get_unfiltered_types(pair.second.classes))
            {
                types.push_back(&type);
            }
        }

        write_component_header(types);
        write_component_source(types);

        for (meta::type const* type : types)
        {
            write_component_class_generated_header(*type);
            write_component_class_header(*type);
            write_component_class_source(*type);
        }
    }
}
