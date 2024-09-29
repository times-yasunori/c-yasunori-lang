{
  description = "The yasunori language";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    treefmt-nix.url = "github:numtide/treefmt-nix";
    flake-parts.url = "github:hercules-ci/flake-parts";
    systems.url = "github:nix-systems/default";
  };

  outputs =
    inputs@{
      self,
      systems,
      nixpkgs,
      treefmt-nix,
      flake-parts,
    }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      imports = [ treefmt-nix.flakeModule ];
      systems = import inputs.systems;

      perSystem =
        {
          config,
          pkgs,
          system,
          ...
        }:
        let
          stdenv = pkgs.stdenv;

          # To make executable binary.
          yasunori = stdenv.mkDerivation {
            # Set executable binary name.
            pname = "yasunori";
            version = "0.1.0";
            src = ./.;

            installPhase = ''
              install -D yasunorize $out/bin/yasunorize
              install -D yasunori $out/bin/yasunori
            '';
          };
        in
        rec {
          treefmt = {
            projectRootFile = "flake.nix";
            programs = {
              nixfmt.enable = true;
              clang-format.enable = true;
              shellcheck.enable = true;
            };

            settings.formatter = { };
          };

          devShells.default = pkgs.mkShell {
            packages = with pkgs; [
              gcc
              make

              nil
            ];
          };

          packages.default = yasunori;
        };
    };
}
