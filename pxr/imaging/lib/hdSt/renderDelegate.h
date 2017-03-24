//
// Copyright 2017 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
#ifndef HDST_RENDER_DELEGATE_H
#define HDST_RENDER_DELEGATE_H

#include "pxr/pxr.h"
#include "pxr/imaging/hd/renderDelegate.h"

PXR_NAMESPACE_OPEN_SCOPE


///
/// HdStRenderDelegate
///
/// The Stream Render Delegate provides a Hydra render that uses a
/// streaming graphics implementation to draw the scene.
///
class HdStRenderDelegate final : public HdRenderDelegate {
public:
    HdStRenderDelegate();
    virtual ~HdStRenderDelegate() = default;

    virtual HdRenderParam *GetRenderParam() const override;

    virtual const TfTokenVector &GetSupportedSprimTypes() const override;
    virtual const TfTokenVector &GetSupportedBprimTypes() const override;

    virtual HdRprim *CreateRprim(TfToken const& typeId,
                                 SdfPath const& rprimId,
                                 SdfPath const& instancerId) override;
    virtual void DestroyRprim(HdRprim *rPrim) override;

    virtual HdSprim *CreateSprim(TfToken const& typeId,
                                 SdfPath const& sprimId) override;
    virtual HdSprim *CreateFallbackSprim(TfToken const& typeId) override;
    virtual void DestroySprim(HdSprim *sPrim) override;

    virtual HdBprim *CreateBprim(TfToken const& typeId,
                                 SdfPath const& bprimId) override;
    virtual HdBprim *CreateFallbackBprim(TfToken const& typeId) override;
    virtual void DestroyBprim(HdBprim *bPrim) override;

    virtual void CommitResources(HdChangeTracker *tracker) override;

private:
    static const TfTokenVector SUPPORTED_SPRIM_TYPES;
    static const TfTokenVector SUPPORTED_BPRIM_TYPES;

    static void _ConfigureReprs();
    HdSprim *_CreateFallbackShaderPrim();

    HdStRenderDelegate(const HdStRenderDelegate &)             = delete;
    HdStRenderDelegate &operator =(const HdStRenderDelegate &) = delete;
};


PXR_NAMESPACE_CLOSE_SCOPE

#endif // HDST_RENDER_DELEGATE_H