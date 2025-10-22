
#include "GetSbasDegradationParameters.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasDegradationParameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasDegradationParameters::CmdName = "GetSbasDegradationParameters";
    const char* const GetSbasDegradationParameters::Documentation = "Get the SBAS degradation parameters for the specified service provider. By default, all degradation parameters are returned. If specific parameter names are provided, only those parameters are returned.\n"
      "\n"
      "Name                      Type         Description\n"
      "------------------------- ------------ -----------------------------------------------------------------------------------------\n"
      "ServiceProvider           string       Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\", \"BDSBAS\" and \"KASS\".\n"
      "DegradationParameterArray array string An array of degradationparameters.\n"
      "                                       Accepted values are: \"BRRC\", \"CLTC_LSB\", \"CLTC_V1\", \"ILTC_V1\", \"CLTC_V0\",\n"
      "                                                            \"ILTC_V0\", \"CGEO_LSB\", \"CGEO_V\", \"IGEO\", \"CER\",\n"
      "                                                            \"CIONO_STEP\", \"IIONO\", \"CIONO_RAMP\", \"RSSUDRE\", \"RSSIONO\"\n"
      "                                                            and \"CCOVARIANCE\"";
    const char* const GetSbasDegradationParameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasDegradationParameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasDegradationParameters);


    GetSbasDegradationParameters::GetSbasDegradationParameters()
      : CommandBase(CmdName, TargetId)
    {}

    GetSbasDegradationParameters::GetSbasDegradationParameters(const std::string& serviceProvider, const std::vector<std::string>& degradationParameterArray)
      : CommandBase(CmdName, TargetId)
    {

      setServiceProvider(serviceProvider);
      setDegradationParameterArray(degradationParameterArray);
    }

    GetSbasDegradationParametersPtr GetSbasDegradationParameters::create(const std::string& serviceProvider, const std::vector<std::string>& degradationParameterArray)
    {
      return std::make_shared<GetSbasDegradationParameters>(serviceProvider, degradationParameterArray);
    }

    GetSbasDegradationParametersPtr GetSbasDegradationParameters::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasDegradationParameters>(ptr);
    }

    bool GetSbasDegradationParameters::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["DegradationParameterArray"])
        ;

    }

    std::string GetSbasDegradationParameters::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasDegradationParameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ServiceProvider", "DegradationParameterArray"}; 
      return names; 
    }


    int GetSbasDegradationParameters::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSbasDegradationParameters::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetSbasDegradationParameters::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetSbasDegradationParameters::degradationParameterArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["DegradationParameterArray"]);
    }

    void GetSbasDegradationParameters::setDegradationParameterArray(const std::vector<std::string>& degradationParameterArray)
    {
      m_values.AddMember("DegradationParameterArray", parse_json<std::vector<std::string>>::format(degradationParameterArray, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
