annotation foo(struct, enum) :Text;
# Declare an annotation 'foo' which applies to struct and enum types.

struct MyType $foo("bar") {
  # Apply 'foo' to to MyType.

  # ...
}

# The possible targets for an annotation are:
#   file, struct, field, union, group, enum, enumerant,
#   interface, method, param, annotation, const.
# You may also specify * to cover them all.
annotation baz(*) :Int32;
# 'baz' can annotate anything!

$baz(1);  # Annotate the file.

struct MyStruct $baz(2) {
  myField @0 :Text = "default" $baz(3);
  myUnion :union $baz(4) {
    # ...
  }
}

enum MyEnum $baz(5) {
  myEnumerant @0 $baz(6);
}

interface MyInterface $baz(7) {
  myMethod @0 (myParam :Text $baz(9)) -> () $baz(8);
}

annotation myAnnotation(struct) :Int32 $baz(10);
const myConst :Int32 = 123 $baz(11);

annotation qux(struct, field) :Void;

struct MyStruct $qux {
  string @0 :Text $qux;
  number @1 :Int32 $qux;
}

annotation corge(file) :MyStruct;

$corge(string = "hello", number = 123);

struct Grault {
  value @0 :Int32 = 123;
}

annotation grault(file) :Grault;

$grault();  # value defaults to 123
$grault(value = 456);
