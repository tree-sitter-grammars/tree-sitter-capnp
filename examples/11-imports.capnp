struct Foo {
  baz @0 :import "bar.capnp".Baz;
  # Use type "Baz" defined in bar.capnp.
}

using Bar = import "bar.capnp";

struct Foo {
  baz @0 :Bar.Baz;
  # Use type "Baz" defined in bar.capnp.
}

using import "bar.capnp".Baz;

struct Foo {
  baz @0 :Baz;
  # Use type "Baz" defined in bar.capnp.
}
