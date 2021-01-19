---
layout: post
title: 'disable an option in YAML config'
date: 2020-12-12 08:31
---

Yaml config file:

```
# remove param0 from the config
param1:  (leave the value as blank)
param2: ~
param3: null
```

Json:

```
{ 'param1': None,
  'param2': ''
}
```

We can't assign `~`, `null` or blank directly in Json, it equals to None in Json, they can be convered by yaml.safe_load(), yaml.safe_dump().
It's same as remove the option from the config file.

The empty string '' isn't null, it has value.
