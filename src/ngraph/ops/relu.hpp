// ----------------------------------------------------------------------------
// Copyright 2018 Nervana Systems Inc.
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

#include "ngraph/node.hpp"
#include "ngraph/ops/op.hpp"
#include "ngraph/ops/util/unary_elementwise_arithmetic.hpp"
#include "ngraph/util.hpp"

#include <memory>

namespace ngraph
{
    namespace op
    {
        /// \brief Elementwise Relu operation for pattern matching.
        ///
        class Relu : public ngraph::op::util::UnaryElementwiseArithmetic
        {
        public:
            /// \brief Constructs an Relu operation.
            ///
            /// \param arg Node that produces the input tensor.
            Relu(std::shared_ptr<ngraph::Node> arg);

            virtual std::shared_ptr<Node> copy_with_new_args(
                const std::vector<std::shared_ptr<Node>>& new_args) const override
            {
                if (new_args.size() != 1)
                {
                    throw ngraph_error("Incorrect number of new arguments");
                }
                return std::make_shared<Relu>(new_args.at(0));
            }

            virtual void generate_adjoints(autodiff::Adjoints& adjoints,
                                           const std::shared_ptr<Node>& delta) override;
        };

        /// \brief Elementwise ReluBackprop operation for pattern matching.
        ///
        class ReluBackprop : public ngraph::op::util::UnaryElementwiseArithmetic
        {
        public:
            /// \brief Constructs an Relu operation.
            ///
            /// \param arg Node that produces the input tensor.
            ReluBackprop(std::shared_ptr<ngraph::Node> delta);

            virtual std::shared_ptr<Node> copy_with_new_args(
                const std::vector<std::shared_ptr<Node>>& new_args) const override
            {
                if (new_args.size() != 1)
                {
                    throw ngraph_error("Incorrect number of new arguments");
                }
                return std::make_shared<Relu>(new_args.at(0));
            }
        };
    }
}