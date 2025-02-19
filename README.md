# il22962_task2

## Overview

This project simulates the random motion of hard disks within a square box. Each disk attempts small random displacements at each step; if a move causes an overlap or violates boundaries, it is reverted. Configurations are saved at each iteration and can be visualized via Python scripts.

## Main Modifications

Header Files

    Reconstructed disk.h and system.h to replace the destroyed headers.
    Added header to their respective files.
    
Source Code Corrections

    Amended missing code in system.cpp and disk.cpp (e.g., distance calculation, uniform random generation, boundary checks).

Optimizations

    Refined the overlap check using <algorithm> and std::any_of.
    
    Enhanced enforceBoundaries using std::clamp.
    
    Added error catching when saving configurations.
    
Makefile

    Introduced a Makefile to streamline compilation (make, make clean).

## Git Navigation

The following commits illustrate key steps:

    FirstPush: Initial code base restoration.

    Created_the_two_header_files: Reintroduced disk.h and system.h.

    Added_system_header_code and Added_disk_header_code: Filled in missing declarations.
    
    Optimised_the_overlap_logic_and_included_algorithm: Improved collision checks.
    
    Added_a_Makefile_to_execute_files: Created the build system.

Use

## git log

to see the full commit history with detailed messages. Each commit message describes the changes and rationale.

## How to Compile and Run

1. Clone or Download this repository.
2. Build the project:
        make
3. Run the executable:
        ./main
4. Output is saved in the confs directory (confs/conf0, confs/conf1, etc.).
5. Use either 
    python3 view.py
        or
    view.ipynb (Jupyter notebook) 
    to interactively plot disk positions.
