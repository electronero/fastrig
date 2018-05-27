/* XTLRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2018 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2016-2018 XTLRig       <https://github.com/xtlrig>, <support@xtlrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __JOBRESULT_H__
#define __JOBRESULT_H__


#include <memory.h>
#include <stdint.h>


#include "common/net/Job.h"


class JobResult
{
public:
    inline JobResult() : poolId(0), diff(0), nonce(0) {}
    inline JobResult(int poolId, const xtlrig::Id &jobId, uint32_t nonce, const uint8_t *result, uint32_t diff, const xtlrig::Algorithm &algorithm) :
        poolId(poolId),
        diff(diff),
        nonce(nonce),
        algorithm(algorithm),
        jobId(jobId)
    {
        memcpy(this->result, result, sizeof(this->result));
    }


    inline uint64_t actualDiff() const
    {
        return Job::toDiff(reinterpret_cast<const uint64_t*>(result)[3]);
    }


    int poolId;
    uint32_t diff;
    uint32_t nonce;
    uint8_t result[32];
    xtlrig::Algorithm algorithm;
    xtlrig::Id jobId;
};

#endif /* __JOBRESULT_H__ */