#include <ngl/lexer.hpp>
#include <ngl/shape_cluster.hpp>

struct path_edge
{

};

int main()
{
    try
    {
        //ngl::lexer lx{ ngl::ngl_shape_cluster };
        ngl::shape_cluster shapes;

        auto space = shapes.add(ngl::shape_element(' '));

        auto letter = shapes.add_fragment(ngl::shape_range('a', 'z'));
        auto digit = shapes.add_fragment(ngl::shape_range('0', '9'));
        auto ob = shapes.add_fragment(ngl::shape_element('{'));
        auto cb = shapes.add_fragment(ngl::shape_element('}'));

        auto colon = shapes.add(ngl::shape_element(':'));
        auto underscore = shapes.add(ngl::shape_element('_'));
        auto identifier_symbol = shapes.add_fragment(ngl::shape_or(letter));
        auto many_identifier_symbol = shapes.add_fragment(ngl::shape_many(identifier_symbol));

        auto raw_identifier = shapes.add(ngl::shape_sequence(letter, many_identifier_symbol), "raw_identifier");


        auto path_edge = shapes.add_parser_fragment(ngl::shape_sequence(colon, raw_identifier), "id_edge_path");
        auto path_identifier = shapes.add_parser(ngl::shape_sequence(raw_identifier, path_edge));
//
        auto SD = shapes.add_parser(ngl::shape_sequence(path_identifier, space, raw_identifier), "SD");
//        auto VD = shapes.add_parser(ngl::shape_sequence(raw_identifier, space, raw_identifier, ob, cb), "VD");

        //auto g = shapes.add(ngl::shape_or(SD, VD), "SD");

/*
     SD
     |     \
    PID     RID
 /   |   \
RID EDGE RID
 */


        shapes.display();

        ngl::lexer lx{ shapes };

        /*
        std::string data = R"(
        ngl:shape scalar_description
        {
            ngc:sequence<ngs:identifier ngs:identifier>
        }
        )";*/

        std::string data = "aa:bb";

        lx.process(data);
        std::cout << "\n" << lx.to_string();

    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }

    return 0;
}

/*
L, NB, L
n 0001 I0 S M1 I++
0 0010 I1 V M1
0 0010 I1 V M1
n 0001 I1 V M0
                I++ I2 S M1*/