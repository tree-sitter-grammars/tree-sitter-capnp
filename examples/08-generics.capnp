struct Map(Key, Value) {
  entries @0 :List(Entry);
  struct Entry {
    key @0 :Key;
    value @1 :Value;
  }
}

struct People {
  byName @0 :Map(Text, Person);
  # Maps names to Person instances.
}

struct PersonMap {
  # Encoded the same as Map(Text, Person).
  entries @0 :List(Entry);
  struct Entry {
    key @0 :Text;
    value @1 :Person;
  }
}

interface Assignable(T) {
  # A generic interface, with non-generic methods.
  get @0 () -> (value :T);
  set @1 (value :T) -> ();
}

interface AssignableFactory {
  newAssignable @0 [T] (initialValue :T)
      -> (assignable :Assignable(T));
  # A generic method.

  newUnsetAssignable @1 [T] () -> (assignable :Assignable(T));
  # Create a new assignable. `get()` on the returned object will
  # throw an exception until `set()` has been called at least once.

  getNamedAssignable @2 (name :Text) -> (assignable :Assignable);
  # Get the `Assignable` with the given name. It is the
  # responsibility of the caller to keep track of the type of each
  # named `Assignable` and cast the returned object appropriately.
}
