# ngl:shape __`[experimental]`__

__`[description]`__

A ngl:shape describes the shape of ngl:data

concrete shape : literals
concept shape : data structure
__`[example]`__


```
ngl:element digit
{
    ngl:shape
    {
        element == [0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9]
    }
}

ngl:concept digit
{
    ngl:data <value>
    ngl:rule
    {
        value == (0 | 1 .. | 9)
    }
}

ngl:shape integer
{
     ngc:many<ngc:digit>
     
     ngl:rule
     {
        integer[0] != 0
     }
}

// ngl:concept program
ngl:concrete<program> source_code (ngl:shape:ngl)
nglc:concrete<program> machine_code (ngl:shape:binary)

// ngl:concept 4
- 0100 ngl:storage:environment | environment:shape : ngl:shape:binary | concept:shape : ngl:shape:binary
- 0100 ngl:storage:source_code | source_code:shape : ngl:shape:string | concept:shape : ngl:shape:binary
- 4 ngl:storage:source_code | source_code:shape : ngl:shape:string | concept:shape : ngl:shape:digit
- quatre ngl:storage:source_code | source_code:shape : ngl:shape:string | concept:shape : ngl:shape:literal_digit 

00001101011111101010111010
[A0FF34951536E9F500] ngl:storage:source_code ngl:shape:string
00001101011111101010111010
```


```
ngl:constant<string, "zeta"> zeta;

ngl:function convert
{
    ngl:concrete <input>
    ngl:shape <input_shape>
    ngl:shape <output_shape>
    .result = nglc:convert<input, output_shape> // use compiler conversion
    // .result = ads:convert<input, output_shape> // custom conversion
}

ngl:convert<4 ngs:string>
ngl:convert<"quatre" ngs:integer>
ngl:convert<"4" ngs:integer>


ngl shape
{
    ngl:rule <?standard>
    ngc:char| escape_symbol = $
            | delimiter = $

    ngl:rule { // html format check }
}

ngl:format xml
{
    .escape_symbol = $
    .delimiter = __
}

ngl:format:xml html
{
    .standard = ngl:rule:xml:html 
}

html test
{__
    <form>
        <input text = "$ zeta $" />
    </form>
}__

ngc:program
{
    ngl::print<test.form.input.text>
}

ngc test
{
    ngl:rule
    {
        .require |fr-fr| a égal zéro
        |ngl|
        .require a == 0
    } 
}

ngl:format:html zeta_form
<form>
    <p>test</p>
    <input text = "$ ngc:string <value> $" />
</form>

ngl:format:json zeta_form
{
    "form": {


ngc:int v = 4
ngl:format<v, ngc:string> // "4"
ngl:format<v, ngc:lang:fr> // quatre


ngl:format log_format
{
    .escape_symbol = [ { } ]
    .delimiter = [ < > ]
}

log{{ temps : <time> [ <level> ] | message : <message> }}




ngl:shape brainfuck
{
    .delimiter [ $ ]
    .incrustation [ $ ]
    .element [ < > + - . , [ ] ]
}

ngl:shape:brainfuck hello_world
{
    +[-->-[>>+>-----<<]<--<---]>-.>>>+.>>..+++[.>]<<<<.+++.------.<<-.>>>>+.
}

```