# ngl:ngl
ngl describe ngl
```
ngl ngl // self description
{
    // describe = ngl:entity:environment
    
    // axiom identifiers
    ngl alias
    ngl environment
    ngl data
    ngl storage
    ngl entity
    ngl edge { is, has, alias }
}

// aliases

ngl::alias ngl:entity:concept ngc
ngl::alias ngl:edge nge

```

# ngl:environment
```
ngl environment
{
    ngl:data
    nge:is -> ngl:storage
}
```

# ngl:environment:data
```
ngl:data
{
    storage
}
```


# ngl:concept
```
ngl concept
{
    storage ngl:entity.storage
}
```

# ngl:entity
```
ngl entity
{
    storage ngl:entity.storage
}
```

# ngl:edge

# ngl:storage
```
ngl storage
{
    ?
}
```
