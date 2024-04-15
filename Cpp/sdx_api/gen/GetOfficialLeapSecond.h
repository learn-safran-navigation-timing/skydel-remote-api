#pragma once

#include <memory>
#include "command_base.h"

#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns the official leap second for a given date
    ///
    /// Name Type     Description
    /// ---- -------- ------------------------------
    /// Date datetime A date expressed in UTC format
    ///

    class GetOfficialLeapSecond;
    typedef std::shared_ptr<GetOfficialLeapSecond> GetOfficialLeapSecondPtr;
    
    
    class GetOfficialLeapSecond : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetOfficialLeapSecond();

      GetOfficialLeapSecond(const Sdx::DateTime& date);

      static GetOfficialLeapSecondPtr create(const Sdx::DateTime& date);
      static GetOfficialLeapSecondPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** date ****
      Sdx::DateTime date() const;
      void setDate(const Sdx::DateTime& date);
    };
    
  }
}

