#pragma once

#include "libhirte/common/common.h"

#include "types.h"

struct Job {
        int ref_count;

        Node *node; /* weak ref */

        JobState state;

        uint32_t id;
        char *object_path;
        char *type;
        char *unit;

        sd_bus_slot *export_slot;

        LIST_FIELDS(Job, jobs);
};


Job *job_new(Node *node, const char *unit, const char *type);
Job *job_ref(Job *job);
void job_unref(Job *job);
void job_unrefp(Job **jobp);

bool job_export(Job *job);

#define _cleanup_job_ _cleanup_(job_unrefp)
#define _cleanup_agent_request_ _cleanup_(agent_request_unrefp)
