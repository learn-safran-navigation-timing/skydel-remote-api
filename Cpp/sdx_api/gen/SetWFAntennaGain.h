#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set The CRPA LNA gain
    ///
    /// Name Type Description
    /// ---- ---- -----------------
    /// Gain int  The CRPA LNA gain
    ///

    class SetWFAntennaGain;
    typedef std::shared_ptr<SetWFAntennaGain> SetWFAntennaGainPtr;
    
    
    class SetWFAntennaGain : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetWFAntennaGain();

      SetWFAntennaGain(int gain);

      static SetWFAntennaGainPtr create(int gain);
      static SetWFAntennaGainPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** gain ****
      int gain() const;
      void setGain(int gain);
    };
    
  }
}

