#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the NavIC NAV message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToNavICNav;
    typedef std::shared_ptr<GetMessageModificationToNavICNav> GetMessageModificationToNavICNavPtr;
    
    
    class GetMessageModificationToNavICNav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToNavICNav();

      GetMessageModificationToNavICNav(const std::string& id);

      static GetMessageModificationToNavICNavPtr create(const std::string& id);
      static GetMessageModificationToNavICNavPtr dynamicCast(CommandBasePtr ptr);
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

