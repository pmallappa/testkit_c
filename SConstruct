#
# Copyright (C) 2019-2020
# 
# Author: Prem Mallappa<prem.mallappa@gmail.com>
#

import os, sys
import SCons
from os.path import join as joinpath

sys.path.extend('scripts')

def AddSiteDir(site_dir):
  """Adds a site directory, as if passed to the --site-dir option.

  Args:
    site_dir: Site directory path to add, relative to the location of the
        SConstruct file.

  This may be called from the SConscript file to add a local site scons
  directory for a project.  This does the following:
     * Adds site_dir/site_scons to sys.path.
     * Imports site_dir/site_init.py.
     * Adds site_dir/site_scons to the SCons tools path.
  """
  # Call the same function that SCons does for the --site-dir option.
  SCons.Script.Main._load_site_scons_dir(
      #SCons.Node.FS.get_default_fs().SConstruct_dir, 
      site_dir)


# Options to improve the default speed of SCons
import multiprocessing
SetOption('max_drift', 2)
SetOption('implicit_cache', 1)
SetOption('num_jobs', multiprocessing.cpu_count())
AddSiteDir('./scripts/')

# local module
import check

tkenv = Environment() 

# Allow overriding the compiler with scons CC=???
if 'CC' in ARGUMENTS: tkenv.Replace(CC = ARGUMENTS['CC'])
if 'CXX' in ARGUMENTS: tkenv.Replace(CXX = ARGUMENTS['CXX'])
if 'CCFLAGS' in ARGUMENTS: tkenv.Append(CCFLAGS = ARGUMENTS['CCFLAGS'])
if 'CXXFLAGS' in ARGUMENTS: tkenv.Append(CXXFLAGS = ARGUMENTS['CXXFLAGS'])


tkitscript = SConscript('SConscript',
                        exports = {'env': tkenv},
                        duplicate = 0,
                        variant_dir = 'build',
                        )

Default(tkitscript)

