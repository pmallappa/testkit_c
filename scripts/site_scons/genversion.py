
version_c = """
#include <stdio.h>

struct {
#if (DEVELOPER > 0) || (RELEASE == 1)
    char       *user_name;
    char       *build_machine;
    char       *build_path;
#endif
    char       *date;
    char       *git_hash;

    int        git_tree_modified;

} version_info = {
#if (DEVELOPER > 0) || (RELEASE == 1)
    %s,
    %s,
    %s,
#endif
    %s,
    %s,
    %d,
};

void
print_version_info(void)
{
    printf("user_name:     %s\n, version_info.user_name);
    printf("build_machine: %s\n, version_info.build_machine);
    printf("build_path:    %s\n, version_info.build_path);
    printf("build_date:    %s\n, version_info.date);
    printf("git_hash:      %s%s\n, version_info.git_hash,
                                   version_info.git_tree_modified
                                    ? "(Dirty)"
                                    : "");
    printf(": %s\n, version_info.user_name);
    //printf("user_name: %s\n, version_info.user_name);
    //printf("user_name: %s\n, version_info.user_name);
    //printf("user_name: %s\n, version_info.user_name);
}

"""

class version_info:
    def __init__(self):
        self.username          = ""
        self.build_machine     = ""
        self.build_path        = ""
        self.date              = ""
        self.git_hash          = ""
        self.git_tree_modified = False



