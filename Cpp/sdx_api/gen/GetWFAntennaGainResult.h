#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetWFAntennaGain.
    ///
    /// Name Type Description
    /// ---- ---- -----------------
    /// Gain int  The CRPA LNA gain
    ///

    class GetWFAntennaGainResult;
    typedef std::shared_ptr<GetWFAntennaGainResult> GetWFAntennaGainResultPtr;
    
    
    class GetWFAntennaGainResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetWFAntennaGainResult();

      GetWFAntennaGainResult(int gain);

      GetWFAntennaGainResult(CommandBasePtr relatedCommand, int gain);

      static GetWFAntennaGainResultPtr create(int gain);

      static GetWFAntennaGainResultPtr create(CommandBasePtr relatedCommand, int gain);
      static GetWFAntennaGainResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** gain ****
      int gain() const;
      void setGain(int gain);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetWFAntennaGainResult);
  }
}

