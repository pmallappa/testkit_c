#
# Copyright (C) 2019-2020
# 
# Author: Prem Mallappa<prem.mallappa@gmail.com>
#
import os
from os.path import join as joinpath


Import('env')

tkenv = env.Clone()

def_cxxflags = ['-std=c++14',
    			]

def_cflags   = ['-funsigned-char', 
                #'-Og',
                '-W', '-Wall', '-Werror',
                '-fstack-protector-all',  
                '-Wno-multichar' , '-Wno-unused-parameter',
                '-Wno-missing-field-initializers',
                '-fno-strict-aliasing',
                #'-ffast-math',
                #'-ftree-vectorize',
                '-falign-functions=32',
                #'-falign-loops=32',
                #'-finstrument-functions',
                '-march=native',
	]

cflags   = []
cxxflags = []
libslist = []
incpath  = ['#include', '#include/testkit']
libpaths = []

tkenv['debug_mode'] = 'all'

try:
    dbg_mode=tkenv['debug_mode']
except KeyError as err:
    print("Keyerror, debug_mode not found, setting to none", err)
    dbg_mode='none'

if dbg_mode != 'none':
    def_cflags +=  ['-ggdb', '-Og']
    
    # remove all optimizations on command line
    opt_list=["-O%s"%x for x in range(1, 10)]
    opt_list.append('-Os')
    for opt in opt_list:
        try:
            tkenv['CFLAGS'].remove(opt)
        except ValueError as err:
            pass
else:
    def_cflags += ['-O3']

cflags   += def_cflags
cxxflags += def_cflags + def_cxxflags

tkenv.Append (
    CXXFLAGS   = cxxflags,
    CFLAGS     = cflags,
    CPPPATH    = incpath,
    INCPATH    = incpath,
    LIBS       = libslist,
    LIBPATH    = libpaths,
    VARIANTDIR = 'testkit'
)

#
# Figure out some of the things needed by tests
# 
if not tkenv.GetOption('clean'):
    conf = Configure(tkenv)
    if not conf.CheckProg('clang'):
        print('Unable to find clang in path')
        Exit(1)
    if not conf.CheckCXXHeader('mpreal.h'):
        print('Did not find mpreal.h, install libmpfrc++-dev. exiting!')
        # Use one locally available under tests/include/mpreal
        Exit(1)
    if not conf.CheckLibWithHeader(libs='mpfr', header='mpreal.h', language='CXX'): 
        print('Did not find libmpfr.a or libmpfr.so, exiting!')
        Exit(1)
    conf.Finish()

t = SConscript('src/SConscript',
		exports = {'env': tkenv},
		duplicate = 0,
		variant_dir = 'testkit',
		)

Return('t')

