# RankingApi

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**rankingImpactoIncidentes**](RankingApi.md#rankingImpactoIncidentes) | **POST** /RankingImpactoIncidentes/GenerarRanking | Obtener el ranking de entidades


<a name="rankingImpactoIncidentes"></a>
# **rankingImpactoIncidentes**
> kotlin.collections.List&lt;ResponseEntidadDTO&gt; rankingImpactoIncidentes(requestEntidadDTO)

Obtener el ranking de entidades

### Example
```kotlin
// Import classes:
//import org.openapitools.client.infrastructure.*
//import org.openapitools.client.models.*

val apiInstance = RankingApi()
val requestEntidadDTO : kotlin.collections.List<RequestEntidadDTO> =  // kotlin.collections.List<RequestEntidadDTO> | 
try {
    val result : kotlin.collections.List<ResponseEntidadDTO> = apiInstance.rankingImpactoIncidentes(requestEntidadDTO)
    println(result)
} catch (e: ClientException) {
    println("4xx response calling RankingApi#rankingImpactoIncidentes")
    e.printStackTrace()
} catch (e: ServerException) {
    println("5xx response calling RankingApi#rankingImpactoIncidentes")
    e.printStackTrace()
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **requestEntidadDTO** | [**kotlin.collections.List&lt;RequestEntidadDTO&gt;**](RequestEntidadDTO.md)|  |

### Return type

[**kotlin.collections.List&lt;ResponseEntidadDTO&gt;**](ResponseEntidadDTO.md)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

