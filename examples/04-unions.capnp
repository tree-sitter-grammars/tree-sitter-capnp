struct Person {
  # ...

  employment :union {
    # We assume that a person is only one of these.
    unemployed @4 :Void;
    employer @5 :Company;
    school @6 :School;
    selfEmployed @7 :Void;
  }
}

struct Shape {
  area @0 :Float64;

  union {
    circle @1 :Float64;      # radius
    square @2 :Float64;      # width
  }
}
