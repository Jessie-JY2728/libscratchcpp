// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "entity.h"
#include "spimpl.h"
#include "global.h"

namespace libscratchcpp
{

class AssetPrivate;

/*! \brief The Asset class represents a Scratch asset, for example a Costume or a Sound. */
class LIBSCRATCHCPP_EXPORT Asset : public Entity
{
    public:
        Asset(const std::string &name, const std::string &id, const std::string &format);
        Asset(const Asset &) = delete;

        virtual ~Asset() { }

        void setId(const std::string &id);

        const std::string &name() const;

        const std::string &fileName() const;

        const std::string &dataFormat() const;

        const char *data() const;
        void setData(const char *data);

    protected:
        virtual void processData(const char *data) { }

    private:
        spimpl::unique_impl_ptr<AssetPrivate> impl;
};

} // namespace libscratchcpp
