#pragma once

#include <memory>
#include "command_base.h"

#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the SBAS degradation parameters for the specified service provider.
    ///
    /// Name                          Type               Description
    /// ----------------------------- ------------------ -----------------------------------------------------------------------------------------
    /// ServiceProvider               string             Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN", "SDCM", "BDSBAS" and "KASS".
    /// DegradationParameterValueDict dict string:double A dictionary of degradationparameter value pairs.
    ///                                                  Accepted keys are: "BRRC", "CLTC_LSB", "CLTC_V1", "ILTC_V1", "CLTC_V0",
    ///                                                                     "ILTC_V0", "CGEO_LSB", "CGEO_V", "IGEO", "CER", "CIONO_STEP",
    ///                                                                     "IIONO", "CIONO_RAMP", "RSSUDRE", "RSSIONO" and "CCOVARIANCE"
    ///

    class SetSbasDegradationParameters;
    typedef std::shared_ptr<SetSbasDegradationParameters> SetSbasDegradationParametersPtr;
    
    
    class SetSbasDegradationParameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSbasDegradationParameters();

      SetSbasDegradationParameters(const std::string& serviceProvider, const std::map<std::string, double>& degradationParameterValueDict);

      static SetSbasDegradationParametersPtr create(const std::string& serviceProvider, const std::map<std::string, double>& degradationParameterValueDict);
      static SetSbasDegradationParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** degradationParameterValueDict ****
      std::map<std::string, double> degradationParameterValueDict() const;
      void setDegradationParameterValueDict(const std::map<std::string, double>& degradationParameterValueDict);
    };
    
  }
}

