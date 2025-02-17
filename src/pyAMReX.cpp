/* Copyright 2021-2022 The AMReX Community
 *
 * Authors: Axel Huebl
 * License: BSD-3-Clause-LBNL
 */
#include <AMReX_Config.H>
#include <AMReX.H>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;


// forward declarations of exposed classes
void init_AMReX(py::module&);
void init_Arena(py::module&);
void init_Array4(py::module&);
void init_BaseFab(py::module&);
void init_Box(py::module &);
void init_RealBox(py::module &);
void init_BoxArray(py::module &);
void init_CoordSys(py::module&);
void init_Dim3(py::module&);
void init_DistributionMapping(py::module&);
void init_FArrayBox(py::module&);
void init_Geometry(py::module&);
void init_IndexType(py::module &);
void init_IntVect(py::module &);
void init_RealVect(py::module &);
void init_AmrMesh(py::module &);
void init_MultiFab(py::module &);
void init_ParallelDescriptor(py::module &);
void init_ParmParse(py::module &);
void init_Particle(py::module &);
void init_StructOfArrays(py::module &);
void init_ArrayOfStructs(py::module &);
void init_ParticleTile(py::module &);
void init_ParticleContainer(py::module &);
void init_Periodicity(py::module &);
void init_PODVector(py::module &);
void init_Vector(py::module &);


#if AMREX_SPACEDIM == 1
PYBIND11_MODULE(amrex_1d_pybind, m) {
#elif AMREX_SPACEDIM == 2
PYBIND11_MODULE(amrex_2d_pybind, m) {
#elif AMREX_SPACEDIM == 3
PYBIND11_MODULE(amrex_3d_pybind, m) {
#else
#  error "AMREX_SPACEDIM must be 1, 2 or 3"
#endif
    m.doc() = R"pbdoc(
            amrex
            -----
            .. currentmodule:: amrex

            .. autosummary::
               :toctree: _generate
               AmrInfo
               AmrMesh
               Arena
               ArrayOfStructs
               Box
               RealBox
               BoxArray
               Dim3
               FArrayBox
               IntVect
               IndexType
               RealVect
               MultiFab
               ParallelDescriptor
               Particle
               ParmParse
               ParticleTile
               ParticleContainer
               Periodicity
               PODVector
               StructOfArrays
               Vector
    )pbdoc";

    // note: order from parent to child classes
    init_AMReX(m);
    init_Arena(m);
    init_Dim3(m);
    init_IntVect(m);
    init_IndexType(m);
    init_RealVect(m);
    init_Periodicity(m);
    init_Array4(m);
    init_Box(m);
    init_BoxArray(m);
    init_ParmParse(m);
    init_BaseFab(m);
    init_FArrayBox(m);
    init_MultiFab(m);
    init_DistributionMapping(m);
    init_RealBox(m);
    init_CoordSys(m);
    init_Geometry(m);
    init_ParallelDescriptor(m);
    init_Particle(m);
    init_StructOfArrays(m);
    init_ArrayOfStructs(m);
    init_ParticleTile(m);
    init_PODVector(m);
    init_Vector(m);
    init_ParticleContainer(m);
    init_AmrMesh(m);

    // API runtime version
    //   note PEP-440 syntax: x.y.zaN but x.y.z.devN
#ifdef PYAMReX_VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(PYAMReX_VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif

    // authors
    m.attr("__author__") =
        "Axel Huebl, Ryan Sandberg, Shreyas Ananthan, Remi Lehe, "
        "Weiqun Zhang, et al.";

    // API runtime build-time feature variants
    // m.attr("variants") = amrex::getVariants();
    // TODO allow to query runtime versions of all dependencies

    // license SPDX identifier
    m.attr("__license__") = "BSD-3-Clause-LBNL";

    // TODO broken numpy if not at least v1.15.0: raise warning
    // auto numpy = py::module::import("numpy");
    // auto npversion = numpy.attr("__version__");
    // std::cout << "numpy version: " << py::str(npversion) << std::endl;
}
