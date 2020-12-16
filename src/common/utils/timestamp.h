/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2018 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2018-2020 SChernykh   <https://github.com/SChernykh>
 * Copyright 2016-2020 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
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

#ifndef XMRIG_TIMESTAMP_H
#define XMRIG_TIMESTAMP_H


#include <chrono>


namespace xmrig_cuda {


static inline int64_t steadyTimestamp()
{
    using namespace std::chrono;
    if (high_resolution_clock::is_steady) {
        return time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch().count();
    }
    else {
        return time_point_cast<milliseconds>(steady_clock::now()).time_since_epoch().count();
    }
}


static inline int64_t currentMSecsSinceEpoch()
{
    using namespace std::chrono;

    return time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch().count();
}


} /* namespace xmrig_cuda */

#endif /* XMRIG_TIMESTAMP_H */
