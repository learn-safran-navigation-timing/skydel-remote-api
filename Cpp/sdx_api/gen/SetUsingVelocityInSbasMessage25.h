#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether SBAS message 25 should send velocity corrections
    ///
    /// Name        Type Description
    /// ----------- ---- --------------------------------------------------------
    /// UseVelocity bool Whether SBAS message 25 should send velocity corrections
    ///

    class SetUsingVelocityInSbasMessage25;
    typedef std::shared_ptr<SetUsingVelocityInSbasMessage25> SetUsingVelocityInSbasMessage25Ptr;
    
    
    class SetUsingVelocityInSbasMessage25 : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetUsingVelocityInSbasMessage25();

      SetUsingVelocityInSbasMessage25(bool useVelocity);

      static SetUsingVelocityInSbasMessage25Ptr create(bool useVelocity);
      static SetUsingVelocityInSbasMessage25Ptr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** useVelocity ****
      bool useVelocity() const;
      void setUseVelocity(bool useVelocity);
    };
    
  }
}

