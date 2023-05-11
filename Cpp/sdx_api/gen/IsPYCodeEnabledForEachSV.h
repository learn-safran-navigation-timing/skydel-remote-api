#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if the P(Y)-Code is enabled or disabled for each satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------
    /// Signal string Accepted signal keys: "L1P", "L2P"
    ///

    class IsPYCodeEnabledForEachSV;
    typedef std::shared_ptr<IsPYCodeEnabledForEachSV> IsPYCodeEnabledForEachSVPtr;
    
    
    class IsPYCodeEnabledForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsPYCodeEnabledForEachSV();

      IsPYCodeEnabledForEachSV(const std::string& signal);

      static IsPYCodeEnabledForEachSVPtr create(const std::string& signal);
      static IsPYCodeEnabledForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
    
  }
}

