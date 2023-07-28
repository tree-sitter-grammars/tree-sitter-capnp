const std = @import("std");

pub fn build(b: *std.Build) void {
    var lib = b.addStaticLibrary(.{
        .name = "tree-sitter-capnp",
        .target = b.standardTargetOptions(.{}),
        .optimize = b.standardOptimizeOption(.{}),
    });

    lib.linkLibC();
    lib.addCSourceFile(.{ .file = .{ .path = "../../src/parser.c" }, .flags = &[_][]const u8{} });
    // lib.addCSourceFile(.{ .file = .{ .path = "../../src/scanner.c" }, .flags = &[_][]const u8{} });
    lib.addIncludePath(.{ .path = "../../src" });

    b.installArtifact(lib);
}
