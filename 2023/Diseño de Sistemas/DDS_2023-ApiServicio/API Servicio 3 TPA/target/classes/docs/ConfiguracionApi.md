# ConfiguracionApi

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**rankingImpactoIncidentesCambiarCnfNuevoCnfPost**](ConfiguracionApi.md#rankingImpactoIncidentesCambiarCnfNuevoCnfPost) | **POST** /RankingImpactoIncidentes/CambiarCnf/{nuevoCnf} | 


<a name="rankingImpactoIncidentesCambiarCnfNuevoCnfPost"></a>
# **rankingImpactoIncidentesCambiarCnfNuevoCnfPost**
> rankingImpactoIncidentesCambiarCnfNuevoCnfPost(nuevoCnf)



### Example
```kotlin
// Import classes:
//import org.openapitools.client.infrastructure.*
//import org.openapitools.client.models.*

val apiInstance = ConfiguracionApi()
val nuevoCnf : kotlin.Int = 56 // kotlin.Int | El CNF a utilizar
try {
    apiInstance.rankingImpactoIncidentesCambiarCnfNuevoCnfPost(nuevoCnf)
} catch (e: ClientException) {
    println("4xx response calling ConfiguracionApi#rankingImpactoIncidentesCambiarCnfNuevoCnfPost")
    e.printStackTrace()
} catch (e: ServerException) {
    println("5xx response calling ConfiguracionApi#rankingImpactoIncidentesCambiarCnfNuevoCnfPost")
    e.printStackTrace()
}
```

### Parameters

Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **nuevoCnf** | **kotlin.Int**| El CNF a utilizar |

### Return type

null (empty response body)

### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

