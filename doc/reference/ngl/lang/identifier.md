# ngl:lang:identifier

__`[description]`__

An identifier is a unique [ngl:data] created by a [ngl:entity] used to describe another [ngl:data].

__`[edge]`__

- [raw_identifier](#raw_identifier)
- identifier_path
- identifier_autopath
- descriptor_identifier
- described_identifier

---------------------------------------

## raw_identifier

__`[path]`__ [ngl:lang:identifier]()

__`[rule]`__
- must match a-z

---------------------------------------

## alias

__`[path]`__ [ngl:alias]

__`[example]`__
```
? ngl:edge<alias> ngl:concept ngc
ngl:alias<ngl:concept> ngc
```

---------------------------------------

## parametrization

__`[description]`__
Every described identifier can be parameterized

__`[syntax]`__
> *described_identifier*< `(` *described_identifier* *new_identifier* `) list(comma separator)` >

### explicitly required

__`[description]`__
A parameterised identifier can use the order or explicitly named parameters

__`[example]`__

```
ngl:concept:container matrix
{
    ngl:concept:number <rows> // 1
    ngl:concept:number <columns> // 2
    ngl::concept:size ( rows * columns )

    <data_type> .data // 3, redescribe :data from ngl::container
}

// parameters order
matrix<4, 2, ngl::float> float_matrix;
// named parameters
matrix<data_type ngl::float, rows 4, columns 4> float_matrix4x4;
```

---------------------------------------

## concretization

[alias]: #alias
[ngl:data]: /doc/reference/ngl/data
[ngl:entity]: /doc/reference/ngl/entity