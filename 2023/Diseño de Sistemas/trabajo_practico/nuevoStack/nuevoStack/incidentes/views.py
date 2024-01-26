from django.shortcuts import render
from .models import Incidente

def listar_incidentes(request):

    incidentes = Incidente.objects.all()
    return render(request, 'listar_incidentes.html', {'incidentes': incidentes})