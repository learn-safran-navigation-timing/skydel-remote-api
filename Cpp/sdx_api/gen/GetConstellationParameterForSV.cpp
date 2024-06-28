
#include "GetConstellationParameterForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetConstellationParameterForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetConstellationParameterForSV::CmdName = "GetConstellationParameterForSV";
    const char* const GetConstellationParameterForSV::Documentation = "Get \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\" constellation parameter value.\n"
      "\n"
      "General constellation parameters:\n"
      "\n"
      "  Unit         Type     ParamName\n"
      "  sec          double   \"ClockBias\"\n"
      "  sec/sec      double   \"ClockDrift\"\n"
      "  sec/sec^2    double   \"ClockDriftRate\"\n"
      "  meter        double   \"Crs\", \"Crc\", \"Accuracy\"\n"
      "  meter/sec    double   \"Adot\"\n"
      "  rad          double   \"Cis\", \"Cic\", \"Cus\", \"Cuc\", \"M0\", \"BigOmega\", \"I0\", \"LittleOmega\"\n"
      "  rad/sec      double   \"DeltaN\", \"BigOmegaDot\", \"Idot\" \n"
      "  rad/sec^2    double   \"DeltaN0dot\"\n"
      "  sqrt(meter)  double   \"SqrtA\"  \n"
      "  -            double   \"Eccentricity\"\n"
      "  -            integer  \"Week Number\", \"Toe\", \"Transmission Time\"\n"
      "\n"
      "GPS:\n"
      "\n"
      "  Unit         Type     ParamName\n"
      "  sec          double   \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\", \"IscL1ME\", \"IscL2ME\", \"IscL1MR\", \"IscL2MR\"\n"
      "  sec          integer  \"Fit interval\"\n"
      "  -            integer  \"IODE\", \"IODC\", \"UraIndex\"\n"
      "  -            boolean  \"IscL1CaAvailable\", \"IscL2CAvailable\", \"IscL5I5Available\", \"IscL5Q5Available\", \"IscL1CPAvailable\", \"IscL1CDAvailable\", \"IscL1MEAvailable\", \"IscL2MEAvailable\", \"IscL1MRAvailable\", \"IscL2MRAvailable\"\n"
      "\n"
      "Galileo:\n"
      "\n"
      "  Unit         Type     ParamName\n"
      "  sec          double   \"Tgd\"\n"
      "  ns           double   \"BgdE1E5a\", \"BgdE1E5b\"\n"
      "  -            integer  \"SisaE1E5a\", \"SisaE1E5b\", \"IODNAV\" \n"
      "\n"
      "BeiDou:\n"
      "\n"
      "  Unit         Type     ParamName\n"
      "  sec          double   \"Tgd1\", \"Tgd2\", \"TgdB1Cp\", \"TgdB2Ap\"\n"
      "  -            integer  \"IODE\", \"IODC\", \"AODE\", \"AODC\"\n"
      "  -            boolean  \"IscB1CdAvailable\", \"IscB2adAvailable\"\n"
      "\n"
      "QZSS:\n"
      "\n"
      "  Unit         Type     ParamName\n"
      "  sec          double   \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\"\n"
      "  sec          integer  \"Fit interval\"\n"
      "  -            integer  \"IODE\", \"IODC\", \"UraIndex\"\n"
      "  -            boolean  \"IscL1CaAvailable\", \"IscL2CAvailable\", \"IscL5I5Available\", \"IscL5Q5Available\", \"IscL1CPAvailable\", \"IscL1CDAvailable\"\n"
      "\n"
      "NavIC:\n"
      "\n"
      "  Unit         Type     ParamName\n"
      "  sec          double   \"Tgd\", \"IscS\", \"IscL1P\", \"IscL1D\"\n"
      "  -            integer  \"IODEC\", \"UraIndex\"\n"
      "  -            boolean  \"IscSAvailable\", \"IscL1PAvailable\", \"IscL1DAvailable\"\n"
      "\n"
      "\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
      "SvId        int             The Satellite SV ID, or use 0 to apply new value to all satellites.\n"
      "ParamName   string          Parameter name (see table above for accepted names).\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetConstellationParameterForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetConstellationParameterForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetConstellationParameterForSV);


    GetConstellationParameterForSV::GetConstellationParameterForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetConstellationParameterForSV::GetConstellationParameterForSV(const std::string& system, int svId, const std::string& paramName, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetConstellationParameterForSVPtr GetConstellationParameterForSV::create(const std::string& system, int svId, const std::string& paramName, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetConstellationParameterForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetConstellationParameterForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "ParamName", "DataSetName"}; 
      return names; 
    }


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



    std::optional<std::string> GetConstellationParameterForSV::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetConstellationParameterForSV::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
