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
            if (settings::component_name.empty())
            {
                return;
            }

            output out;
            write_projection(out);
            std::string filename = (settings::output / settings::component_name).string();
            filename += ".h";
            out.save_as(filename);
        }

        void create_natvis()
        {
            if (settings::component_name.empty() || !settings::create_natvis)
            {
                return;
            }

            output out;
            write_natvis(out);
            std::string filename = (settings::output / settings::component_name).string();
            filename += ".natvis";
            out.save_as(filename);
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
            for (meta::type const& type : pair.second.classes)
            {
                if (type.is_filtered())
                {
                    types.push_back(&type);
                }
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
