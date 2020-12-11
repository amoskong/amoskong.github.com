---
layout: post
title: YAML: disable an option
date: 2020-12-12 08:30 
---

```
param1:  (blank)
param2: ~
param3: null
param4: null
```

Json

```
{ 'param1': None,
  'param2': ''
}
```

We can't assign `~`, `null` or blank directly in Json, it equals to None in Json, they can be convered by yaml.safe_load(), yaml.safe_dump().
It's same as remove the option from the config file.

The empty string '' isn't null, it has value.
