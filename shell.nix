with import <nixpkgs> {};
stdenv.mkDerivation {
    name = "dev-environment"; # Probably put a more meaningful name here
    buildInputs = [ pkg-config zlib qt6.qmake qt6.full gcc ];
}
