#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if P(Y)-Code is enabled for the specified satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------
    /// Signal string Accepted signal keys: "L1P", "L2P"
    /// SvId   int    The satellite's SV ID 1..32 (use 0 for all SVs)
    ///

    class IsPYCodeEnabledForSV;
    typedef std::shared_ptr<IsPYCodeEnabledForSV> IsPYCodeEnabledForSVPtr;
    
    
    class IsPYCodeEnabledForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsPYCodeEnabledForSV();

      IsPYCodeEnabledForSV(const std::string& signal, int svId);

      static IsPYCodeEnabledForSVPtr create(const std::string& signal, int svId);
      static IsPYCodeEnabledForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

