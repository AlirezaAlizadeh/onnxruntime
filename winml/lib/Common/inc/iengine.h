// Copyright (c) Microsoft Corporation.
// Licensed under the MIT License.

#pragma once

namespace Windows::AI::MachineLearning {


MIDL_INTERFACE("eaae30b5-7381-432d-9730-322136b02371") IModelInfo : IUnknown {
    STDMETHOD(GetAuthor)(const char** out, size_t* len) PURE;
    STDMETHOD(GetName)(const char** out, size_t* len) PURE;
    STDMETHOD(GetDomain)(const char** out, size_t* len) PURE;
    STDMETHOD(GetDescription)(const char** out, size_t* len) PURE;
    STDMETHOD(GetVersion)(int64_t* out) PURE ;
    STDMETHOD(GetModelMetadata)(ABI::Windows::Foundation::Collections::IMapView<HSTRING, HSTRING> ** metadata) PURE;
    STDMETHOD(GetInputFeatures)(ABI::Windows::Foundation::Collections::IVectorView<winml::ILearningModelFeatureDescriptor>** features) PURE;
    STDMETHOD(GetOutputFeatures)(ABI::Windows::Foundation::Collections::IVectorView<winml::ILearningModelFeatureDescriptor>** features) PURE;
};

MIDL_INTERFACE("1b198b76-5c44-480d-837c-8433ca6eaf99") IModel : IUnknown {
    STDMETHOD(GetModelInfo)(IModelInfo** info) PURE;
    STDMETHOD(CloneModel)(IModel** copy) PURE;
};

MIDL_INTERFACE("30c99886-38d2-41cb-a615-203fe7d7daac") IEngine : IUnknown {
};


MIDL_INTERFACE("5eddd25a-70ad-46ef-a445-78fbaf792c2f") IEngineFactory : IUnknown {
    STDMETHOD(CreateModel)(_In_ const char* model_path, _In_ size_t len, _Outptr_ IModel** out) PURE;
    STDMETHOD(CreateModel)( _In_ void* data, _In_ size_t size, _Outptr_ IModel** out) PURE;
    STDMETHOD(CreateEngine)(_Outptr_ IEngine** out) PURE;
};


}