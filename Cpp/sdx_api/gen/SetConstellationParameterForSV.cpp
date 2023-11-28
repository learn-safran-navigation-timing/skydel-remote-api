
#include "gen/SetConstellationParameterForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetConstellationParameterForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetConstellationParameterForSV::CmdName = "SetConstellationParameterForSV";
    const char* const SetConstellationParameterForSV::Documentation = "Set \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\" or \"NavIC\" constellation parameter value.\n\nGeneral constellation parameters:\n\n  Unit         Type     ParamName\n  sec          double   \"ClockBias\"\n  sec/sec      double   \"ClockDrift\"\n  sec/sec^2    double   \"ClockDriftRate\"\n  meter        double   \"Crs\", \"Crc\", \"Accuracy\"\n  meter/sec    double   \"Adot\"\n  rad          double   \"Cis\", \"Cic\", \"Cus\", \"Cuc\", \"M0\", \"BigOmega\", \"I0\", \"LittleOmega\"\n  rad/sec      double   \"DeltaN\", \"BigOmegaDot\", \"Idot\" \n  rad/sec^2    double   \"DeltaN0dot\"\n  sqrt(meter)  double   \"SqrtA\"  \n  -            double   \"Eccentricity\"\n  -            integer  \"Week Number\", \"Toe\", \"Transmission Time\"\n\nGPS:\n\n  Unit         Type     ParamName\n  sec          double   \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\", \"IscL1ME\", \"IscL2ME\", \"IscL1MR\", \"IscL2MR\"\n  sec          integer  \"Fit interval\"\n  -            integer  \"IODE\", \"IODC\", \"UraIndex\"\n  -            boolean  \"IscL1CaAvailable\", \"IscL2CAvailable\", \"IscL5I5Available\", \"IscL5Q5Available\", \"IscL1CPAvailable\", \"IscL1CDAvailable\", \"IscL1MEAvailable\", \"IscL2MEAvailable\", \"IscL1MRAvailable\", \"IscL2MRAvailable\"\n\nGalileo:\n\n  Unit         Type     ParamName\n  sec          double   \"Tgd\"\n  ns           double   \"BgdE1E5a\", \"BgdE1E5b\"\n  -            integer  \"SisaE1E5a\", \"SisaE1E5b\", \"IODNAV\" \n\nBeiDou:\n\n  Unit         Type     ParamName\n  sec          double   \"Tgd1\", \"Tgd2\", \"TgdB1Cp\", \"TgdB2Ap\"\n  -            integer  \"IODE\", \"IODC\", \"AODE\", \"AODC\"\n  -            boolean  \"IscB1CdAvailable\", \"IscB2adAvailable\"\n\nQZSS:\n\n  Unit         Type     ParamName\n  sec          double   \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\"\n  sec          integer  \"Fit interval\"\n  -            integer  \"IODE\", \"IODC\", \"UraIndex\"\n  -            boolean  \"IscL1CaAvailable\", \"IscL2CAvailable\", \"IscL5I5Available\", \"IscL5Q5Available\", \"IscL1CPAvailable\", \"IscL1CDAvailable\"\n\nNavIC:\n\n  Unit         Type     ParamName\n  sec          double   \"Tgd\"\n  -            integer  \"IODEC\", \"UraIndex\"";

    REGISTER_COMMAND_FACTORY(SetConstellationParameterForSV);


    SetConstellationParameterForSV::SetConstellationParameterForSV()
      : CommandBase(CmdName)
    {}

    SetConstellationParameterForSV::SetConstellationParameterForSV(const std::string& system, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetConstellationParameterForSV::SetConstellationParameterForSV(const std::string& system, int svId, const std::string& paramName, int val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetConstellationParameterForSV::SetConstellationParameterForSV(const std::string& system, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetConstellationParameterForSVPtr SetConstellationParameterForSV::create(const std::string& system, int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetConstellationParameterForSV>(system, svId, paramName, val, dataSetName);
    }

    SetConstellationParameterForSVPtr SetConstellationParameterForSV::create(const std::string& system, int svId, const std::string& paramName, int val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetConstellationParameterForSV>(system, svId, paramName, val, dataSetName);
    }

    SetConstellationParameterForSVPtr SetConstellationParameterForSV::create(const std::string& system, int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetConstellationParameterForSV>(system, svId, paramName, val, dataSetName);
    }

    SetConstellationParameterForSVPtr SetConstellationParameterForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetConstellationParameterForSV>(ptr);
    }

    bool SetConstellationParameterForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && (parse_json<double>::is_valid(m_values["Val"]) || parse_json<int>::is_valid(m_values["Val"]) || parse_json<bool>::is_valid(m_values["Val"]))
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetConstellationParameterForSV::documentation() const { return Documentation; }


    int SetConstellationParameterForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetConstellationParameterForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetConstellationParameterForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetConstellationParameterForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetConstellationParameterForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetConstellationParameterForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetConstellationParameterForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    template<typename Type>
    Type SetConstellationParameterForSV::val() const
    {
      return parse_json<Type>::parse(m_values["Val"]);
    }

    template<typename Type>
    void SetConstellationParameterForSV::setVal(Type val)
    {
      m_values.AddMember("Val", parse_json<Type>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetConstellationParameterForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetConstellationParameterForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
