/*
 * Copyright (C) 2018 Heinrich-Heine-Universitaet Duesseldorf,
 * Institute of Computer Science, Department Operating Systems
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */

#ifndef IBPERFMONITOR_IBFABRIC_H
#define IBPERFMONITOR_IBFABRIC_H

#include "IbNode.h"

namespace IbPerfLib {

/**
 * Represents an entire Infiniband-fabric.
 *
 * @author Fabian Ruhland, Fabian.Ruhland@hhu.de, 05.05.2018
 */
class IbFabric {

public:
    /**
     * Constructor.
     */
    IbFabric();

    /**
     * Destructor.
     */
    ~IbFabric();

    /**
     * Refreshes the performance counters on all nodes in the fabbric.
     */
    void RefreshCounters();

    /**
     * Resets the performance counters on all nodes in the fabric.
     */
    void ResetCounters();

    /**
     * Get the amount of nodes in the fabric.
     */
    uint32_t GetNumNodes() const {
        return m_numNodes;
    }

    /**
     * Get all of the nodes in the fabric in a vector.
     */
    std::vector<IbNode *> &GetNodes() {
        return m_nodes;
    }

    /**
     * Write fabric information to an output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const IbFabric &o) {
        os << "Discovered " << o.m_numNodes << " nodes in the fabric:" << std::endl;

        for (const auto &node : o.m_nodes) {
            os << *node << std::endl;
        }

        return os;
    }

private:
    /**
     * Pointer to an ibnd_fabric-struct.
     * The ibnetdisc-library can be used to fill it with information about the fabric.
     */
    ibnd_fabric_t *m_fabric;

    /**
     * The amount of nodes in the fabric.
     */
    uint32_t m_numNodes;

    /**
     * All of the nodes in the fabric.
     */
    std::vector<IbNode *> m_nodes;
};

}

#endif