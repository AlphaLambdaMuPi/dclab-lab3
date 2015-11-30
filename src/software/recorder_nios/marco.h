
#define SETTER(type, name)  \
  type name; \
  void set_##name (type a) { name = a };
