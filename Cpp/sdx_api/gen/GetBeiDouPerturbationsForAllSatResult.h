#pragma once

#include <memory>
#include "command_result.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouPerturbationsForAllSat.
    ///
    /// Name Type         Description
    /// ---- ------------ -----------
    /// Crs  array double Crs (meter)
    /// Crc  array double Crc (meter)
    /// Cis  array double Crs (rad)
    /// Cic  array double Crc (rad)
    /// Cus  array double Cus (rad)
    /// Cuc  array double Cuc (rad)
    ///

    class GetBeiDouPerturbationsForAllSatResult;
    typedef std::shared_ptr<GetBeiDouPerturbationsForAllSatResult> GetBeiDouPerturbationsForAllSatResultPtr;
    
    
    class GetBeiDouPerturbationsForAllSatResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouPerturbationsForAllSatResult();

      GetBeiDouPerturbationsForAllSatResult(CommandBasePtr relatedCommand, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc);
  
      static GetBeiDouPerturbationsForAllSatResultPtr create(CommandBasePtr relatedCommand, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc);
      static GetBeiDouPerturbationsForAllSatResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** crs ****
      std::vector<double> crs() const;
      void setCrs(const std::vector<double>& crs);


      // **** crc ****
      std::vector<double> crc() const;
      void setCrc(const std::vector<double>& crc);


      // **** cis ****
      std::vector<double> cis() const;
      void setCis(const std::vector<double>& cis);


      // **** cic ****
      std::vector<double> cic() const;
      void setCic(const std::vector<double>& cic);


      // **** cus ****
      std::vector<double> cus() const;
      void setCus(const std::vector<double>& cus);


      // **** cuc ****
      std::vector<double> cuc() const;
      void setCuc(const std::vector<double>& cuc);
    };
  }
}

