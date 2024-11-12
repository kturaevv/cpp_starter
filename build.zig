const std = @import("std");

const CXX_FLAGS = [_][]const u8{
    "-std=c++23",
    "-Wall",
    "-Wextra",
    "-Wpedantic",
    "-Werror",
    "-Wno-unused-variable",
    "-Wno-infinite-recursion",
    "-Werror=implicit-function-declaration",
    "-Wshadow",
    "-Wuninitialized",
    "-Wunused-label",
    "-Wunused-lambda-capture",
};

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "cpp_starter",
        .target = target,
        .optimize = optimize,
    });

    exe.addCSourceFiles(.{
        .root = b.path("src"),
        .files = &.{"main.cpp"},
        .flags = &CXX_FLAGS,
    });

    exe.linkLibCpp();
    exe.linkSystemLibrary("fmt");
    b.installArtifact(exe);

    // Create a "run" step for main
    const run_cmd = b.addRunArtifact(exe);
    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);
}
