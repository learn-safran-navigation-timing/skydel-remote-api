#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the GLONASS G1 P-Code message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToGlonassG1PNav;
    typedef std::shared_ptr<GetMessageModificationToGlonassG1PNav> GetMessageModificationToGlonassG1PNavPtr;
    
    
    class GetMessageModificationToGlonassG1PNav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetMessageModificationToGlonassG1PNav();

      GetMessageModificationToGlonassG1PNav(const std::string& id);

      static GetMessageModificationToGlonassG1PNavPtr create(const std::string& id);
      static GetMessageModificationToGlonassG1PNavPtr dynamicCast(CommandBasePtr ptr);
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

