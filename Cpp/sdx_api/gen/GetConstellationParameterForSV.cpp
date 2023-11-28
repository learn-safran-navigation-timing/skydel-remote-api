
#include "gen/GetConstellationParameterForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConstellationParameterForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConstellationParameterForSV::CmdName = "GetConstellationParameterForSV";
    const char* const GetConstellationParameterForSV::Documentation = "Get \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\" or \"NavIC\" constellation parameter value.\n\nGeneral constellation parameters:\n\n  Unit         Type     ParamName\n  sec          double   \"ClockBias\"\n  sec/sec      double   \"ClockDrift\"\n  sec/sec^2    double   \"ClockDriftRate\"\n  meter        double   \"Crs\", \"Crc\", \"Accuracy\"\n  meter/sec    double   \"Adot\"\n  rad          double   \"Cis\", \"Cic\", \"Cus\", \"Cuc\", \"M0\", \"BigOmega\", \"I0\", \"LittleOmega\"\n  rad/sec      double   \"DeltaN\", \"BigOmegaDot\", \"Idot\" \n  rad/sec^2    double   \"DeltaN0dot\"\n  sqrt(meter)  double   \"SqrtA\"  \n  -            double   \"Eccentricity\"\n  -            integer  \"Week Number\", \"Toe\", \"Transmission Time\"\n\nGPS:\n\n  Unit         Type     ParamName\n  sec          double   \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\", \"IscL1ME\", \"IscL2ME\", \"IscL1MR\", \"IscL2MR\"\n  sec          integer  \"Fit interval\"\n  -            integer  \"IODE\", \"IODC\", \"UraIndex\"\n  -            boolean  \"IscL1CaAvailable\", \"IscL2CAvailable\", \"IscL5I5Available\", \"IscL5Q5Available\", \"IscL1CPAvailable\", \"IscL1CDAvailable\", \"IscL1MEAvailable\", \"IscL2MEAvailable\", \"IscL1MRAvailable\", \"IscL2MRAvailable\"\n\nGalileo:\n\n  Unit         Type     ParamName\n  sec          double   \"Tgd\"\n  ns           double   \"BgdE1E5a\", \"BgdE1E5b\"\n  -            integer  \"SisaE1E5a\", \"SisaE1E5b\", \"IODNAV\" \n\nBeiDou:\n\n  Unit         Type     ParamName\n  sec          double   \"Tgd1\", \"Tgd2\", \"TgdB1Cp\", \"TgdB2Ap\"\n  -            integer  \"IODE\", \"IODC\", \"AODE\", \"AODC\"\n  -            boolean  \"IscB1CdAvailable\", \"IscB2adAvailable\"\n\nQZSS:\n\n  Unit         Type     ParamName\n  sec          double   \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\"\n  sec          integer  \"Fit interval\"\n  -            integer  \"IODE\", \"IODC\", \"UraIndex\"\n  -            boolean  \"IscL1CaAvailable\", \"IscL2CAvailable\", \"IscL5I5Available\", \"IscL5Q5Available\", \"IscL1CPAvailable\", \"IscL1CDAvailable\"\n\nNavIC:\n\n  Unit         Type     ParamName\n  sec          double   \"Tgd\"\n  -            integer  \"IODEC\", \"UraIndex\"";

    REGISTER_COMMAND_FACTORY(GetConstellationParameterForSV);


    GetConstellationParameterForSV::GetConstellationParameterForSV()
      : CommandBase(CmdName)
    {}

    GetConstellationParameterForSV::GetConstellationParameterForSV(const std::string& system, int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForSVPtr GetConstellationParameterForSV::create(const std::string& system, int svId, const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetConstellationParameterForSV>(system, svId, paramName, dataSetName);
    }

    GetConstellationParameterForSVPtr GetConstellationParameterForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetConstellationParameterForSV>(ptr);
    }

    bool GetConstellationParameterForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetConstellationParameterForSV::documentation() const { return Documentation; }


    int GetConstellationParameterForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetConstellationParameterForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetConstellationParameterForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetConstellationParameterForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetConstellationParameterForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetConstellationParameterForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetConstellationParameterForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetConstellationParameterForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetConstellationParameterForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
