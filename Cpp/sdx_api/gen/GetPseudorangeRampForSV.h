#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get PSR ramp event. This function lets user change the pseudorange of any satellite.
    /// If SV ID is set to 0, the change is applied to all satellites.
    /// 
    ///           Hold Start Time
    ///           |         Hold Stop Time
    ///           |         |
    ///           ...........
    ///          ..         ...
    ///         ..            ...
    ///   .......               .........> Time
    ///         |               |
    ///         Start Time      Stop Time
    /// 
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------------------------------
    /// Id   string Unique identifier automatically set by simulator if empty string.
    ///             The IDs pool is common between all system.
    ///

    class GetPseudorangeRampForSV;
    typedef std::shared_ptr<GetPseudorangeRampForSV> GetPseudorangeRampForSVPtr;
    
    
    class GetPseudorangeRampForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPseudorangeRampForSV();

      GetPseudorangeRampForSV(const std::string& id);

      static GetPseudorangeRampForSVPtr create(const std::string& id);
      static GetPseudorangeRampForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

