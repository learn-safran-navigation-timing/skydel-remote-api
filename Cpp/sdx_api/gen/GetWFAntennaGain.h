#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get The CRPA LNA gain
    ///
    /// 
    ///

    class GetWFAntennaGain;
    typedef std::shared_ptr<GetWFAntennaGain> GetWFAntennaGainPtr;
    
    
    class GetWFAntennaGain : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetWFAntennaGain();

      static GetWFAntennaGainPtr create();
      static GetWFAntennaGainPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

