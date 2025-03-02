cc_library(
    name = "bullet_headers",
    hdrs = glob(["src/*.h"]),  # Inclui btBulletDynamicsCommon.h e semelhantes
    strip_include_prefix = "src",  # Remove o prefixo "src"
    visibility = ["//visibility:public"],
)

cc_library(
    name = "LinearMath",
    srcs = glob(["src/LinearMath/**/*.cpp"]),
    hdrs = glob(["src/LinearMath/**/*.h"]),
    includes = ["src"],
    deps = [":bullet_headers"],
)

cc_library(
    name = "BulletCollision",
    srcs = glob(["src/BulletCollision/**/*.cpp"]),
    hdrs = glob(["src/BulletCollision/**/*.h"]),
    includes = [
        "src",
        "src/BulletCollision",
    ],
    deps = [":LinearMath", ":bullet_headers"],
)

cc_library(
    name = "BulletDynamics",
    srcs = glob(["src/BulletDynamics/**/*.cpp"]),
    hdrs = glob(["src/BulletDynamics/**/*.h"]),
    includes = [
        "src",
        "src/BulletDynamics",
    ],
    deps = [":BulletCollision", ":LinearMath", ":bullet_headers"],
    copts = ["-Wno-unused-variable"],
)

cc_library(
    name = "bullet",
    deps = [":BulletDynamics", ":BulletCollision", ":LinearMath", ":bullet_headers"],
    visibility = ["//visibility:public"],
)