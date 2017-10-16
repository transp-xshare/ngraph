// ----------------------------------------------------------------------------
// Copyright 2017 Nervana Systems Inc.
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// ----------------------------------------------------------------------------

#pragma once

#include "ngraph/ops/op.hpp"

namespace ngraph
{
    namespace op
    {
        class Sum : public Builtin
        {
        public:
            ///
            /// @param arg The tensor view to be summedn.
            /// @param summed_axes The axis positions (0-based) to be summed.
            ///
            Sum(const std::shared_ptr<Node>& arg, const AxisSet& summed_axes)
                : Builtin({arg})
                , m_summed_axes(summed_axes)
            {
            }

            virtual std::string description() const override { return "Sum"; }
            virtual void propagate_types() override;

            const AxisSet& get_summed_axes() const { return m_summed_axes; }
        protected:
            AxisSet m_summed_axes;
        };
    }
}