#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command PseudorangeRamp is deprecated since 21.3. You may use PseudorangeRampForSV.
    /// 
    /// Get PSR ramp event. This function lets user change the pseudorange of any satellite.
    /// If PRN is set to 0, the change is applied to all satellites.
    /// 
    ///          Hold Start Time
    ///          |     Hold Stop Time
    ///          |     |
    ///          ...........
    ///        ..       ...
    ///        ..        ...
    ///   .......           .........> Time
    ///       |           |
    ///       Start Time      Stop Time
    /// 
    ///
    /// Name Type   Description
    /// ---- ------ -------------------------------------------------
    /// Id   string Unique identifier automatically set by simulator.
    ///

    class GetPseudorangeRamp;
    typedef std::shared_ptr<GetPseudorangeRamp> GetPseudorangeRampPtr;
    
    
    class GetPseudorangeRamp : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeRamp();

      GetPseudorangeRamp(const std::string& id);
  
      static GetPseudorangeRampPtr create(const std::string& id);
      static GetPseudorangeRampPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
  }
}

